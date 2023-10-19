/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extention.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoquocb <mdoquocb@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:20:06 by mdoquocb          #+#    #+#             */
/*   Updated: 2021/10/07 14:15:32 by mdoquocb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int ft_check_extension(char *str, char *extension) {
  int len_str;
  int len_ext;

  len_str = ft_strlen(str);
  len_ext = ft_strlen(extension);
  while (len_ext > 0) {
    if (extension[--len_ext] != str[--len_str])
      return (-1);
  }
  return (1);
}
