/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sampler_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelessa <cool.3meu@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 19:14:37 by dmelessa          #+#    #+#             */
/*   Updated: 2020/12/04 22:35:01 by dmelessa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libft.h"
#include "utils.h"

static int	realloc_sampler_manager(t_sampler_manager *sampler_manager,
									size_t new_size)
{
	cl_float2	*new_samples;
	cl_float2	*new_disk_samples;
	cl_float3	*new_hemisphere_samples;

	if (!(new_samples = malloc(sizeof(cl_float2) * new_size)))
		return (ERROR);
	ft_memcpy(new_samples, sampler_manager->samples,
				sizeof(cl_float2) * sampler_manager->samples_size);
	free(sampler_manager->samples);
	sampler_manager->samples = new_samples;
	if (!(new_disk_samples = malloc(sizeof(cl_float2) * new_size)))
		return (ERROR);
	ft_memcpy(new_disk_samples, sampler_manager->disk_samples,
				sizeof(cl_float2) * sampler_manager->samples_size);
	free(sampler_manager->disk_samples);
	sampler_manager->disk_samples = new_disk_samples;
	if (!(new_hemisphere_samples = malloc(sizeof(cl_float3) * new_size)))
		return (ERROR);
	ft_memcpy(new_hemisphere_samples, sampler_manager->hemisphere_samples,
				sizeof(cl_float3) * sampler_manager->samples_size);
	free(sampler_manager->hemisphere_samples);
	sampler_manager->hemisphere_samples = new_hemisphere_samples;
	sampler_manager->samples_malloc_size = new_size;
	return (SUCCESS);
}

static int	realloc_samplers(t_sampler_manager *sampler_manager,
								size_t new_size)
{
	t_sampler *new_samplers;

	if (!(new_samplers = malloc(sizeof(t_sampler) * new_size)))
		return (ERROR);
	ft_memcpy(new_samplers, sampler_manager->samplers,
			(sampler_manager->count - 1) * sizeof(t_sampler));
	free(sampler_manager->samplers);
	sampler_manager->samplers = new_samplers;
	sampler_manager->samplers_malloc_size = new_size;
	return (SUCCESS);
}

t_sampler	init_sampler(t_sampler_type sampler_type, int num_samples)
{
	t_sampler	sampler;

	sampler.count = 0;
	sampler.jump = 0;
	sampler.type = num_samples == 1 ? regular_grid : sampler_type;
	sampler.num_samples = num_samples ? num_samples : NUM_SAMPLES;
	sampler.num_sets = NUM_SETS;
	if (sampler_type == none)
	{
		sampler.type = sampler_type;
		sampler.num_samples = 1;
		sampler.num_sets = 1;
		return (sampler);
	}
	return (sampler);
}

int			init_sampler1(t_sampler *sampler, t_sampler_type type,
					int num_samples, int samples_type)
{
	sampler->count = 0;
	sampler->jump = 0;
	sampler->type = num_samples == 1 ? regular_grid : type;
	sampler->num_samples = num_samples ? num_samples : NUM_SAMPLES;
	sampler->num_sets = NUM_SETS;
	sampler->samples_type = samples_type;
	if (type == none)
	{
		sampler->type = type;
		sampler->num_samples = 1;
		sampler->num_sets = 1;
	}
	return (1);
}

void		map_sp(t_sampler_manager *m, t_sampler *s)
{
	int	a;

	a = m->samples_malloc_size;
	if (m->samples_size >= (a = m->samples_malloc_size))
		m->samples = ft_realloc(m->samples, a,
			m->samples_malloc_size = 2 * m->samples_size);
	generate_samples(*s, m->samples + s->offset);
	if (s->samples_type & DISK_SAMPLES)
	{
		if (m->disk_samples_size >= (a = m->disk_samples_malloc_size))
			m->disk_samples = ft_realloc(m->disk_samples, a,
			m->disk_samples_malloc_size = 2 * m->disk_samples_size);
		map_samples_to_unit_disk(*s, m->samples + s->offset,
								m->disk_samples + s->disk_samples_offset);
	}
	a = m->hemisphere_samples_malloc_size;
	if (s->samples_type & HEMISPHERE_SAMPLES)
	{
		if (m->hemisphere_samples_size >= m->hemisphere_samples_malloc_size)
			m->hemisphere_samples = ft_realloc(m->hemisphere_samples, a,
				m->hemisphere_samples_malloc_size =
					2 * m->hemisphere_samples_size);
		map_samples_to_hemisphere(*s, m->samples + s->offset,
			m->hemisphere_samples + s->hemisphere_samples_offset, 0.0f);
	}
}

int			new_sampler(t_sampler_manager *mngr,
					t_sampler_type sampler_type,
					int nsp,
					int type)
{
	t_sampler	s;

	init_sampler1(&s, sampler_type, nsp, type);
	s.offset = mngr->samples_size / sizeof(cl_float2);
	mngr->samples_size += nsp * s.num_sets * sizeof(cl_float2);
	if (type & DISK_SAMPLES)
	{
		s.disk_samples_offset = mngr->disk_samples_size / sizeof(cl_float2);
		mngr->disk_samples_size += nsp * s.num_sets * sizeof(cl_float2);
	}
	if (type & HEMISPHERE_SAMPLES)
	{
		s.hemisphere_samples_offset = mngr->hemisphere_samples_size
									/ sizeof(cl_float3);
		mngr->hemisphere_samples_size += nsp * s.num_sets * sizeof(cl_float3);
	}
	if (++mngr->count - 1 >= mngr->samplers_malloc_size)
		realloc_samplers(mngr, mngr->count * 2);
	map_sp(mngr, &s);
	mngr->samplers[mngr->count - 1] = s;
	return (mngr->count - 1);
}

int			init_sampler_manager(t_sampler_manager *sampler_manager)
{
	sampler_manager->count = 0;
	sampler_manager->samplers_malloc_size = 0;
	sampler_manager->samples_size = 0;
	sampler_manager->samples_malloc_size = 0;
	sampler_manager->disk_samples_size = 0;
	sampler_manager->disk_samples_malloc_size = 0;
	sampler_manager->hemisphere_samples_size = 0;
	sampler_manager->hemisphere_samples_malloc_size = 0;
	sampler_manager->samplers = NULL;
	sampler_manager->hemisphere_samples = NULL;
	sampler_manager->samples = NULL;
	sampler_manager->disk_samples = NULL;
	new_sampler(sampler_manager, regular_grid, 16384,
				DISK_SAMPLES | HEMISPHERE_SAMPLES);
	return (SUCCESS);
}
