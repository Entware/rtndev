#
# Copyright (C) 2017 Lucian Cristian
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/uclibc++.mk

PKG_NAME:=mariadb
PKG_VERSION:=5.5.57
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=\
	http://ftp.hosteurope.de/mirror/archive.mariadb.org/$(PKG_NAME)-$(PKG_VERSION)/source/ \
	https://mirror.netcologne.de/$(PKG_NAME)/$(PKG_NAME)-$(PKG_VERSION)/source/ \
	https://mirror.lstn.net/$(PKG_NAME)/$(PKG_NAME)-$(PKG_VERSION)/source/ \
	http://lon1.mirrors.digitalocean.com/$(PKG_NAME)/$(PKG_NAME)-$(PKG_VERSION)/source/ \
	http://ftp.kaist.ac.kr/$(PKG_NAME)/$(PKG_NAME)-$(PKG_VERSION)/source/ \
	http://ftp.utexas.edu/$(PKG_NAME)/$(PKG_NAME)-$(PKG_VERSION)/source/
PKG_HASH:=5dbde98d7e4a5a1721b6cbed7898b2549a88866247951cf586057975c6cea641
PKG_MAINTAINER:=Lucian Cristian <lucian.cristian@gmail.com>
PKG_LICENSE:=GPL-2.0
PKG_BUILD_DEPENDS:=mariadb/host libncurses libreadline
HOST_BUILD_DEPENDS += mariadb/host
PKG_BUILD_PARALLEL:=1
PKG_USE_MIPS16:=0

PKG_FIXUP:=libtool

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk
include $(INCLUDE_DIR)/host-build.mk

define Package/libmariadb
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=$(CXX_DEPENDS) +zlib +libpthread +libncurses +libreadline
  TITLE:=MariaDB client library
  URL:=http://dev.mysql.com/
  PROVIDES:=libmysqlclient libmysqlclient-r
  CONFLICTS:=libmysqlclient libmysqlclient-r
endef

define Package/mariadb/Default
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libmariadb
  TITLE:=MariaDB Server
  URL:=http://mariadb.org/
  SUBMENU:=database
endef

define Package/mariadb-client
  $(call Package/mariadb/Default)
  TITLE+= client applications
endef

define Package/mariadb-client-extra
  $(call Package/mariadb/Default)
  DEPENDS+=+mariadb-client
  TITLE+= additional client applications
endef

define Package/mariadb-server
  $(call Package/mariadb/Default)
  TITLE+= server
  DEPENDS+=+libpcre +resolveip
  PROVIDES:=mysql-server
  CONFLICTS:=mysql-server
endef

CMAKE_OPTIONS += -DSTACK_DIRECTION=-1
CMAKE_OPTIONS += -DWITH_WSREP=OFF
CMAKE_OPTIONS += -DWITHOUT_TOKUDB=1
CMAKE_OPTIONS += -DIMPORT_EXECUTABLES=$(HOST_BUILD_DIR)/host/import_executables.cmake

define Host/Patch/Default
endef

define Host/Compile
	( cd $(HOST_BUILD_DIR)/ ; mkdir host/ ; cd host ; cmake -DWITHOUT_TOKUDB=1 .. ; $(MAKE) IMPORT_EXECUTABLES )
endef

define Host/Install
endef

define Build/Compile
	+$(MAKE) $(PKG_JOBS) -C "$(PKG_BUILD_DIR)" \
		SUBDIRS="include" \
		DESTDIR="$(PKG_INSTALL_DIR)"
	$(MAKE) -C "$(PKG_BUILD_DIR)" \
		SUBDIRS="include" \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		install
endef

define Build/InstallDev
	$(INSTALL_DIR) $(2)/bin $(1)/opt/bin $(1)/opt/include $(1)/opt/lib $(1)/opt/share/aclocal
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mysql_config $(1)/opt/bin/
	ln -sf $(STAGING_DIR)/opt/bin/mysql_config $(2)/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/include/mysql $(1)/opt/include/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/lib*.a $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/share/aclocal/mysql.m4 $(1)/opt/share/aclocal/
endef

define Package/libmariadb/install
	$(INSTALL_DIR) $(1)/opt/lib $(1)/opt/lib/mysql
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmysqlclient*.so* $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/mysql_clear_password.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/dialog.so $(1)/opt/lib/mysql/
endef

define Package/mariadb-client/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqlcheck $(1)/opt/bin/
endef

define Package/mariadb-client-extra/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/innochecksum $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqlaccess $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqladmin $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqlbug $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqldump $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqldumpslow $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql_find_rows $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql_fix_extensions $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqlimport $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqlshow $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqlslap $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql_waitpid $(1)/opt/bin/
	# fix perl path
	find $(1)/opt/bin -type f | xargs $(SED) 's|/usr/bin/perl|/opt/bin/perl|'
endef

define Package/mariadb-server/install
	$(INSTALL_DIR) $(1)/opt/bin $(1)/opt/share/mysql $(1)/opt/lib/mysql $(1)/opt/etc/mysql $(1)/opt/etc/mysql/conf.d $(1)/opt/etc/init.d \
			$(1)/opt/var/mysql $(1)/opt/var/log/mariadb
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqld $(1)/opt/bin/mysqld
	$(INSTALL_BIN) files/S70mariadbd $(1)/opt/etc/init.d/
	# these two need perl and should go into their own package which depends on perl + dbi + ?
	# $(INSTALL_BIN) files/mysqlreport $(1)/opt/bin/
	# $(INSTALL_BIN) files/innotop $(1)/opt/bin/
	$(INSTALL_CONF) files/my.cnf $(1)/opt/etc/mysql/
	$(INSTALL_CONF) files/conf.d/utf-8.cnf $(1)/opt/etc/mysql/conf.d/
	$(CP) $(PKG_INSTALL_DIR)/opt/share/* $(1)/opt/share/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/adt_null.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/auth_socket.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/feedback.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/ha_archive.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/ha_blackhole.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/ha_federated.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/ha_federatedx.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/ha_innodb.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/ha_sphinx.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/mypluglib.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/qa_auth_client.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/qa_auth_interface.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/qa_auth_server.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/query_cache_info.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/semisync_master.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/semisync_slave.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/server_audit.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/sphinx.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/mysql/sql_errlog.so $(1)/opt/lib/mysql/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/msql2mysql $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/my_print_defaults $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/myisamchk $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/myisam_ftdump $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/myisamlog $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/myisampack $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/aria_pack $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/aria_read_log $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/aria_ftdump $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/aria_chk $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/aria_dump_log $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql_convert_table_format $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/scripts/mysql_install_db $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql_plugin $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql_secure_installation $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql_setpermission $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql_tzinfo_to_sql $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql_upgrade $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysql_zap $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqlbinlog $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqld_multi $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqld_safe $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/mysqlhotcopy $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/perror $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/replace $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/resolve_stack_dump $(1)/opt/bin/
	$(SED) 's,basedir="",basedir="/opt",g' $(1)/opt/bin/mysql_install_db
	# fix perl path
	find $(1)/opt/bin -type f | xargs $(SED) 's|/usr/bin/perl|/opt/bin/perl|'
endef

define Package/mariadb/conffiles
/opt/etc/mysql/my.cnf
/opt/etc/mysql/conf.d
endef

$(eval $(call HostBuild))

$(eval $(call BuildPackage,libmariadb))
$(eval $(call BuildPackage,mariadb-client))
$(eval $(call BuildPackage,mariadb-client-extra))
$(eval $(call BuildPackage,mariadb-server))
