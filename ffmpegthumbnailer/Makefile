# PDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2006-2011 OpenWrt.org
# Copyright (C) 2015-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=ffmpegthumbnailer
PKG_VERSION:=2.3.1
PKG_REV:=75828029fa93c604a758be01a523377b3392187e
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/dirkvdb/ffmpegthumbnailer.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=532b7d9ebe512618d9118ca23bbbf25ef24d26bd6f74de526b38edd274d728c6

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/libffmpegthumbnailer
	SECTION:=libs
	CATEGORY:=Libraries
	TITLE:=library to create thumbnails
	URL:=https://github.com/dirkvdb/ffmpegthumbnailer
	DEPENDS:=+libffmpeg-full +libpng +libjpeg +libstdcpp
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libffmpegthumbnailer/description
 libffmpegthumbnailer is a library that can be used to create thumbnails
 for your video files.
endef

define Package/libffmpegthumbnailer/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libffmpegthumbnailer*.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libffmpegthumbnailer))
