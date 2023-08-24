#
# Copyright (C) 2011-2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libmediainfo
PKG_VERSION:=23.07
PKG_REV:=5c311149c15d41158d9d423a44bd9146de2e1754
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/MediaArea/MediaInfoLib.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=cadbc0e59dec61711b3ca521a5a7f377af99284f984ef9bf6b82d3e515061923

PKG_BUILD_PARALLEL:=1
PKG_INSTALL:=1
PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/libmediainfo
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libzen +zlib
	TITLE:=Mediainfo support library
	URL:=http://mediaarea.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/libmediainfo/description
 LibediaInfo is a convenient unified display of the most relevant technical and tag data for
 video and audio files.
endef

CONFIGURE_PATH:=Project/GNU/Library

#CONFIGURE_ARGS += \
#	--with-libcurl=$(STAGING_DIR)/opt

MAKE_PATH:=$(CONFIGURE_PATH)

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/include/MediaInfo $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/MediaInfoDLL $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmediainfo.so* $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/libmediainfo.pc $(1)/opt/lib/pkgconfig
endef

define Package/libmediainfo/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libmediainfo.so* $(1)/opt/lib
endef

$(eval $(call BuildPackage,libmediainfo))
