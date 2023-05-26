#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libzen
PKG_VERSION:=0.4.41
PKG_REV:=894980d3ecbc843d6ac685493f8f2ed5c2b6864c
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/MediaArea/ZenLib.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=62388bb7a2ba3b9aadb74d6ce517a73175f6e479f00866955a70b4941396f998

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
