/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:37:46 by jpatrici          #+#    #+#             */
/*   Updated: 2025/01/22 16:38:37 by jpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"
#include <fcntl.h>

int main(void)
{
	printf("%i\n", open("/usr/bin/", O_DIRECTORY));
	printf("%i\n", open("/usr/bin/ls", O_DIRECTORY));
}
