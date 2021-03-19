#
# Copyright (C) 2006-2011 OpenWrt.org
# Copyright (C) 2015-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ffmpegthumbnailer
PKG_VERSION:=2.2.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://github.com/dirkvdb/ffmpegthumbnailer/releases/download/$(PKG_VERSION)
PKG_HASH:=1cb24059c38223f657b300c84dd80491b7040d4b69471c4fea69be862bc99b5b

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

CMAKE_OPTIONS = -DCMAKE_BUILD_TYPE=Release
# -DENABLE_STATIC=On

define Package/libffmpegthumbnailer/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libffmpegthumbnailer*.so* $(1)/opt/lib/
endef

$(eval $(call BuildPackage,libffmpegthumbnailer))
