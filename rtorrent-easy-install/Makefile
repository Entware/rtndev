#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rtorrent-easy-install
PKG_VERSION:=0.2
PKG_RELEASE:=3a

include $(INCLUDE_DIR)/package.mk

define Package/rtorrent-easy-install
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=BitTorrent
	DEPENDS:=+rutorrent-plugin-rpc +screen +php7-cgi \
	    +lighttpd-mod-fastcgi +lighttpd-mod-scgi +lighttpd-mod-auth \
	    +lighttpd-mod-authn_file
	TITLE:=Easy installation script for rtorrent with web UI
	URL:=http://github.com/abhinavseewoosungkur/scripts/blob/develop/rutorrent-entware.sh
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/rtorrent-easy-install/description
 This pakage helps to configure rtorrent with rutorrent web interface. Please
 note, we assuming no lighttpd installed\configured on your system before!. 
 Just answer a few question to get torrent-client working.
endef

define Build/Prepare
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/rtorrent-easy-install/install
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S85rtorrent $(1)/opt/etc/init.d/
	$(INSTALL_DIR) $(1)/opt/etc/rtorrent/{watchdir,session}
endef

define Package/rtorrent-easy-install/postinst
#!/bin/sh

echo -e "\n#### Welcome to rtorrent easy installation script! \n\
    We assuming no lighttpd/rtorrent/rutorrent was installed before! \n\
    Please, answer a few question to configure torrent client. \n\
    Default aswers given in [brackets], just hit Enter to accept it.\n"

www_cfg=/opt/etc/lighttpd/conf.d/99-rtorrent-fastcgi-scgi-auth.conf
rt_cfg=/opt/etc/rtorrent/rtorrent.conf

#### Configuring web-server
cat > $$www_cfg << EOF

#server.modules += ( "mod_scgi" )
scgi.server = (
  "/RPC2" =>
    ( "127.0.0.1" =>
     (
        "socket" => "/opt/var/rpc.socket",
        "check-local" => "disable"
      )
    )
)

#server.modules += ( "mod_fastcgi" )
fastcgi.server = (
  ".php" =>
    ( "localhost" =>
      ( "socket" => "/tmp/php-fcgi.sock",
        "bin-path" => "/opt/bin/php-fcgi",
        "max-procs" => 1,
        "bin-environment" =>
          ( "PHP_FCGI_CHILDREN" => "2",
             "PHP_FCGI_MAX_REQUESTS" => "1000"
          )
      )
    )
)

EOF

echo -n "Type \"username:password\" if you want to protect Web UI or hit Enter \
 to leave password protection disabled []: "
read user_password
if [ ! -z "$$user_password" ]
then
    echo "$$user_password" > /opt/etc/lighttpd/rutorrent_passwd
    cat >> $$www_cfg << EOF

server.modules += ( "mod_auth" )
auth.backend = "plain"
auth.backend.plain.userfile = "/opt/etc/lighttpd/rutorrent_passwd"
auth.require = (
  "/rutorrent/" =>
    ( "method"  => "basic",
      "realm"   => "restricted area",
      "require" => "valid-user"
    )
)

EOF
fi

echo -n "Which port should be used by web interface? [81]: "
read web_port
[ -z "$$web_port" ] && web_port=81
echo "server.port = $$web_port" >> $$www_cfg

#### Configuring torrent client
cat > $$rt_cfg << EOF
max_uploads = 8
session = /opt/etc/rtorrent/session
schedule = watch_directory,5,5,load_start=/opt/etc/rtorrent/watchdir/*.torrent
schedule = untied_directory,5,5,stop_untied=
schedule = low_diskspace,5,60,close_low_diskspace=100M
bind = 0.0.0.0
port_range = 51411-51411
check_hash = yes
trackers.use_udp.set = yes
encryption = allow_incoming,enable_retry,prefer_plaintext
dht = auto
dht_port = 51412
protocol.pex.set = yes
scgi_local = /opt/var/rpc.socket
encoding_list = UTF-8
max_uploads_global = 32
max_downloads_global = 64
EOF
echo -n "Enter (maximal) download speed in KB/s [2048]: "
read download_speed
[ -z "$$download_speed" ] && download_speed=2048
echo "download_rate = $$download_speed" >> $$rt_cfg

echo -n "Enter (maximal) upload speed in KB/s [$$download_speed]: "
read upload_speed
[ -z "$$upload_speed" ] && upload_speed=$$download_speed
echo "upload_rate = $$upload_speed" >> $$rt_cfg

echo -n "Enter folder name on USB drive where torrent content should be \
    stored [/opt/torrents]: "
read -r storage_folder
[ -z "$$storage_folder" ] && storage_folder=/opt/torrents
[ -d "$$storage_folder" ] || mkdir -p $$storage_folder
echo "directory = $$storage_folder" >> $$rt_cfg

echo -n -e "\n Done! You may open 51411-51412 TCP/UDP ports on your router to\n\
    facilitate uploading/donwloading. It's not necessary but recommended.\n\
    rutorrent web UI will be available at following URL:\n\n\
    http://<ip_address_of_router>:<port>/rutorrent\n\n\
    Do you wish to start torrent client? [y]: "
read wish_to_start
[ -z "$$wish_to_start" ] && wish_to_start=y
if [ "$$wish_to_start" == "y" ]
then
    /opt/etc/init.d/S80lighttpd start
    /opt/etc/init.d/S85rtorrent start
fi
endef

$(eval $(call BuildPackage,rtorrent-easy-install))
