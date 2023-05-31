# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/03 16:51:36 by mthiry            #+#    #+#              #
#    Updated: 2023/02/03 16:51:38 by mthiry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Based on debian_buster
FROM debian:buster

# Install requirements
RUN apt-get update && apt-get install -y mariadb-server

# Copy MariaDB configuration file into /etc
COPY ./conf/conf.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools /var/www/

# Expose port 3306
EXPOSE 3306

# Run SQL
RUN service mysql start && \
    mysql < /var/www/base.sql && \
    rm -f /var/www/base.sql
CMD ["mysqld", "--bind-address=0.0.0.0"]