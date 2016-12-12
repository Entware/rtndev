#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=i2pd
PKG_VERSION:=2.10.2-20161207
PKG_REV:=381f6b184e6ad3e71270d3465518c01956720df9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/orignal/i2pd
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/i2pd
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libopenssl +boost-filesystem +boost-regex +boost-program_options +boost-date_time +libatomic
	TITLE:=simplified C++ implementation of I2P client
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/i2pd/description
 i2p router for Linux written on C++.
endef

TARGET_LDFLAGS += -latomic

define Package/i2pd/conffiles
/opt/etc/i2p.conf
endef

define Package/i2pd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/i2pd $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) ./files/i2p.conf $(1)/opt/etc
	$(INSTALL_BIN) ./files/S30i2p $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/var/lib
endef

$(eval $(call BuildPackage,i2pd))
