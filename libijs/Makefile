#
# Copyright (C) 2011-2017 Entware
# Copyright (C) 2013 Francisco Borges
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Makefile taken from http://github.com/FranciscoBorges/openwrt-printing-packages
#
# Abandoned in 2006

include $(TOPDIR)/rules.mk

PKG_NAME:=ijs
PKG_VERSION:=0.35
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://www.openprinting.org/download/$(PKG_NAME)/download
PKG_HASH:=11a5f5084488c480f3ff5a24d64d7147bb64272bf60a0ba51330a56c5b50cab9

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libijs
	SECTION:=libs
	CATEGORY:=Libraries
	SUBMENU:=Printing
	TITLE:=IJS raster image transport protocol
	URL:=http://www.openprinting.org
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/libijs/description
 IJS raster image transport protocol
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/ijs $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libijs.a $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/ijs.pc $(1)/opt/lib/pkgconfig
endef

$(eval $(call BuildPackage,libijs))
