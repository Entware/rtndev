#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libmatroska
PKG_VERSION:=1.4.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://dl.matroska.org/downloads/libmatroska
PKG_HASH:=38a61dd5d87c070928b5deb3922b63b2b83c09e2e4a10f9393eecb6afa9795c8

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/libmatroska
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libebml
	TITLE:=MKV container format library
	URL:=http://matroska.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libmatroska/description
 libmatroska - extensible open standard Audio/Video container format library
endef

CMAKE_OPTIONS += -DBUILD_SHARED_LIBS=YES

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/matroska $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmatroska.so* $(1)/opt/lib/
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/cmake $(1)/opt/lib/
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libmatroska.pc $(1)/opt/lib/pkgconfig/
endef

define Package/libmatroska/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmatroska.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libmatroska))
