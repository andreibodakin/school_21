# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klavada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/06 17:21:03 by klavada           #+#    #+#              #
#    Updated: 2020/09/08 13:45:03 by klavada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && apt-get upgrade
RUN apt-get install -y	nginx \
						openssl \
						wget \
						vim \
						php7.3 \
						php7.3-fpm \
						php7.3-mysql \
						php7.3-mbstring \
						php7.3-cli \
						mariadb-server

COPY ./srcs/* ./tmp/

CMD bash ./tmp/start.sh
