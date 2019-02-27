#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ympd
PKG_VERSION:=1.3.0-20180329
PKG_REV:=612f8fc0b2c47fc89d403e4a044541c6b2b238c8
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/notandy/ympd.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/ympd
	SECTION:=sound
	CATEGORY:=Sound
	DEPENDS:=+libmpdclient +libopenssl +libpthread
	TITLE:=MPD Web GUI
	URL:=http://www.ympd.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ympd/description
 Standalone MPD Web GUI written in C, utilizing Websockets and Bootstrap/JS.
endef

define Package/ympd/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/ympd $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S90ympd $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,ympd))
