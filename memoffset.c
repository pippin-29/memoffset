/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoffset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:12:49 by dhadding          #+#    #+#             */
/*   Updated: 2023/07/24 11:55:08 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned int		u32;

#define MEM_IO				0x04000000

#define memoffset(type, MEM, OFFSET, index, offset) *((volatile type*)(MEM+OFFSET+(index*offset)))

#define REG_KEYINPUT		memoffset(u32, MEM_IO, 0x0130, 1, 0x0)

#define REG_DMA0DAD			memoffset(u32, MEM_IO, 0x00B4, 0, 0x0C)
#define REG_DMA1DAD			memoffset(u32, MEM_IO, 0x00B4, 1, 0x0C)
#define REG_DMA2DAD			memoffset(u32, MEM_IO, 0x00B4, 2, 0x0C)
#define REG_DMA3DAD			memoffset(u32, MEM_IO, 0x00B4, 3, 0x0C)

/*

	memoffset can define a register location in memory
	memoffset takes 4 arguments
	1. type - type of pointer
	2. MEM - Designation of Memory Block (for example - MEM_VRAM)
	3. OFFSET - Designation Within Memory Block
	4. index - defines the index for the succeeding offset (index*offset)
	5. offset - Used for register locations that are grouped within 
			the second designation
	
	This method is tested and working on my GameBoyAdvance 
			as well as mGBA (emulator).

	Primarily designed for ease of use when referring to documentation,
	But also for easy reference during code review.

*/