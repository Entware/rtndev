#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libzen
PKG_VERSION:=0.4.39
PKG_REV:=13b9d3dbd2088390fbdccab32ae4560526389fbc
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/MediaArea/ZenLib.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=0b2d5bc145cbe1790b38489d008406806f7b67d37831a27524a9c3448965656b

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/libzen
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=libstdcpp
	TITLE:=C++ derivate classes
	URL:=http://mediaarea.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libzen/description
 Small C++ derivate classes to have an easier life.
endef

CONFIGURE_PATH:=Project/GNU/Library

MAKE_PATH:=$(CONFIGURE_PATH)

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/include/ZenLib $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libzen.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libzen.pc $(1)/opt/lib/pkgconfig
endef

define Package/libzen/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libzen.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libzen))
