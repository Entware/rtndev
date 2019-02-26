#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2012

include $(TOPDIR)/rules.mk

PKG_NAME:=nload
PKG_VERSION:=0.7.4
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_HASH:=c1c051e7155e26243d569be5d99c744d8620e65fa8a7e05efcf84d01d9d469e5

include $(INCLUDE_DIR)/package.mk

define Package/nload
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libstdcpp +libncurses
	TITLE:=real time monitor for network traffic
	URL:=http://nload.sourceforge.net
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/nload/description
 nload is a real time monitor for network traffic
endef

define Package/nload/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/$(PKG_NAME) $(1)/opt/bin/
endef

$(eval $(call BuildPackage,nload))
