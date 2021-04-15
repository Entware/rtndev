#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libzen
PKG_VERSION:=0.4.39
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://mediaarea.net/download/source/libzen/$(PKG_VERSION)
PKG_HASH:=bd2772ab1ae4e375cdbbbdd114ad8471ebe67bf78c76e3812d66c7d462ed8ae7

PKG_INSTALL:=1
PKG_FIXUP:=autoreconf

PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

include $(INCLUDE_DIR)/package.mk

define Package/libzen
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=Mediainfo support library
	URL:=http://mediaarea.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libzen/description
 libzen - used by mediainfo
endef

CONFIGURE_PATH:=Project/GNU/Library

CONFIGURE_ARGS += \
	--enable-static \
	--disable-shared

MAKE_PATH:=$(CONFIGURE_PATH)

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include $(1)/opt/lib $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/include/ZenLib $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libzen.a $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libzen.pc $(1)/opt/lib/pkgconfig
endef

$(eval $(call BuildPackage,libzen))
