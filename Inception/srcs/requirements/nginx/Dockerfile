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
RUN apt-get update && apt-get install -y nginx openssl

# Configure SSL
RUN mkdir -p /etc/nginx/ssl/private
RUN mkdir -p /etc/nginx/ssl/certs
RUN openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/private/mthiry.key \
    -out /etc/nginx/ssl/certs/mthiry.crt \
    -subj "/C=BE/ST=Bruxelles/L=Bruxelles/O=19 School/OU=mthiry/CN=mthiry/"

# Copy Nginx configuration file into /etc/
COPY ./conf/nginx.conf /etc/nginx/conf.d/

# Create debug folder
RUN mkdir -p /run/nginx/

# Expose port 443
EXPOSE 443

# Run Nginx
CMD ["nginx", "-g", "daemon off;"]