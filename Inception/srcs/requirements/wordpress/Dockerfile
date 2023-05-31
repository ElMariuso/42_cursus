# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 18:28:49 by mthiry            #+#    #+#              #
#    Updated: 2023/02/03 19:03:10 by mthiry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Based on debian_buster
FROM debian:buster

# Install requirements
RUN apt-get update -y
RUN apt-get install -y \
    wget \
    curl \
    php \
    php-cgi \
    php-mysqli \
    php-fpm \
    php-pdo \
    php-gd php-cli \
    php-mbstring

# WP-CLI installation
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# www.conf in the right directory
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

# Create Run php directory
RUN mkdir /run/php

# Go to html directory
WORKDIR /var/www/html/

# Expose port 9000
EXPOSE 9000

# Entrypoint configuration
COPY ./tools/wp_script.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/wp_script.sh
ENTRYPOINT ["/usr/local/bin/wp_script.sh"]

# Run PHP
CMD ["/usr/sbin/php-fpm7.3", "-F"]