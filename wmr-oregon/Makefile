#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2013

include $(TOPDIR)/rules.mk

PKG_NAME:=wmr-oregon
PKG_VERSION:=0.4-2013-01-23
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/wmr \
	http://entware.dyndns.info/sources
PKG_HASH:=bc11d81fe0eb21dea3ed673a0f968e3b4ada30b6b8e760a4ed0fbf4856e1d442

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-0.4

include $(INCLUDE_DIR)/package.mk

define Package/wmr-oregon
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libhid +libsqlite3
	TITLE:=Oregon Scientific USB Station Logger/Reader
	URL:=https://code.google.com/archive/p/wmr/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/wmr-oregon/description
 Oregon Scientific WMR100/200/WMRS200/I300/I600/RMS300/RMS600
 USB Station Logger/Reader
endef

define Build/Configure
	$(SED) 's,/usr/include/usb.h,$(STAGING_DIR)/opt/include/usb.h,g' $(PKG_BUILD_DIR)/config.h
	$(SED) 's,/usr/local/lib/_include_/hid.h,$(STAGING_DIR)/opt/include/hid.h,g' $(PKG_BUILD_DIR)/config.h
	$(SED) 's,/usr/local/lib/_include_/sqlite3.h,$(STAGING_DIR)/opt/include/sqlite3.h,g' $(PKG_BUILD_DIR)/config.h
endef

TARGET_CFLAGS += \
	-fPIC \
	-DLANG_ENG \

define Package/wmr-oregon/conffiles
/opt/etc/wmr/wmr.conf
endef

define Package/wmr-oregon/install
	$(INSTALL_DIR) $(1)/opt/lib/wmr
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libwmr-{alarm,file,rrd,snmp,sql,upd}.so \
	    $(1)/opt/lib/wmr
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/wmrd $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/script/wmr_*.sh $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/wmr
	$(INSTALL_CONF) $(PKG_BUILD_DIR)/contrib/wmr.conf $(1)/opt/etc/wmr
	$(CP) -R $(PKG_BUILD_DIR)/script/wmr_etc/etc/wmr/* $(1)/opt/etc/wmr
endef

$(eval $(call BuildPackage,wmr-oregon))
