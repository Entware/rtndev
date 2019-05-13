#
# Copyright (C) 2006-2015 OpenWrt.org
# Copyright (C) 2015-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# UTF8 support added

include $(TOPDIR)/rules.mk

PKG_NAME:=bacula
PKG_VERSION:=9.4.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/bacula
PKG_HASH:=4fb41cc460dcaa3674d2ceba2ef0de0fbd8bb56e413857a1c9fe60c2dca54b1d

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/bacula
  SECTION:=utils
  CATEGORY:=Utilities
  DEPENDS:=+libopenssl +libwrap +libstdcpp +libsqlite3 +liblzo +libacl +libcap +gawk
  TITLE:=Open Source Network Backup Solution
  URL:=http://www.bacula.org/
endef

define Package/bacula/description
  Bacula is a set of computer programs that permits the system administrator to manage backup,
  recovery, and verification of computer data across a network of computers of different kinds.
  Bacula can also run entirely upon a single computer and can backup to various types of media, including tape and disk.
endef

CONFIGURE_VARS += \
	ac_cv_func_setpgrp_void=yes \
	ac_cv_func_chflags=no \
	ac_cv_sys_file_offset_bits=64 \
	ac_cv_sys_large_files=yes \
	ac_cv_sys_largefile_CFLAGS=-D_LARGFILE_SOURCE \
	ac_cv_sys_largefile_LDFLAGS= \
	ac_cv_sys_largefile_LIBS= \
	ac_cv_sys_largefile_source=yes


CONFIGURE_ARGS += \
	--enable-largefile \
	--sysconfdir=/opt/etc/bacula/ \
	--with-scriptdir=/opt/etc/bacula/scripts \
	--with-archivedir=/opt/bacula/tmp \
	--with-pid-dir=/opt/var/run \
	--with-subsys-dir=/opt/var/run/subsys \
	--enable-smartalloc \
	--disable-conio --enable-readline \
	--with-readline=$(STAGING_DIR)/opt/include/readline \
	--with-openssl=$(STAGING_DIR)/opt/include/openssl \
	--with-sqlite3=$(STAGING_DIR)/opt/include \
	--with-tcp-wrappers=$(STAGING_DIR)/opt/include \
	--without-x \
	--disable-static \
	--includedir=$(STAGING_DIR)/opt/include \
	--oldincludedir=$(STAGING_DIR)/opt/include

define Package/bacula/conffiles
/opt/etc/bacula/bacula-dir.conf
/opt/etc/bacula/bacula-fd.conf
/opt/etc/bacula/bacula-sd.conf
/opt/etc/bacula/bconsole.conf
endef


define Package/bacula/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/sbin/* $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/*.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/etc/bacula/scripts
	$(INSTALL_DIR) $(1)/opt/bacula/tmp
	$(INSTALL_DIR) $(1)/opt/bacula/working
	$(INSTALL_DIR) $(1)/opt/bacula/log
	$(INSTALL_DIR) $(1)/opt/var/run/subsys/
	$(CP) $(PKG_INSTALL_DIR)/opt/etc/bacula/*.conf $(1)/opt/etc/bacula
	$(CP) $(PKG_INSTALL_DIR)/opt/etc/bacula/scripts/* $(1)/opt/etc/bacula/scripts
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S* $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,bacula))
