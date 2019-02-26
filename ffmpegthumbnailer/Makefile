#
# Copyright (C) 2006-2011 OpenWrt.org
# Copyright (C) 2015-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ffmpegthumbnailer
PKG_VERSION:=2.2.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://github.com/dirkvdb/ffmpegthumbnailer/releases/download/$(PKG_VERSION)
PKG_HASH:=e5c31299d064968198cd378f7488e52cd5e738fac998eea780bc77d7f32238c2

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
  libffmpegthumbnailer is a library that can be used to create thumbnails for your video files
endef

CMAKE_OPTIONS = -DCMAKE_BUILD_TYPE=Release
# -DENABLE_STATIC=On

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/libffmpegthumbnailer $(1)/opt/include/
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libffmpegthumbnailer*.so* $(1)/opt/lib/
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libffmpegthumbnailer.pc $(1)/opt/lib/pkgconfig/
endef

define Package/libffmpegthumbnailer/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libffmpegthumbnailer*.so* $(1)/opt/lib/
endef

$(eval $(call BuildPackage,libffmpegthumbnailer))
