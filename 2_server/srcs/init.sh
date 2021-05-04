service nginx start
service mysql start
service php7.3-fpm start
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
# GRANT ALL PRIVILEGES ON db.table TO user.host
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost';" | mysql -u root --skip-password
# reload the tables so that changes made with INSERT, UPDATE or DELETE come into place
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password
# give the root user permission over the DB (create a DB user)
# use default plugin, which I believe is mysql_native_password
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password
