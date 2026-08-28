# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=mediainfo
PKG_VERSION:=26.05
PKG_REV:=4728f24b666117a19d36515d95b9367fbb37aaf6
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/MediaArea/MediaInfo.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=9f4d96925c38267123c100cb0d0a2d85fae4ad9988986f552cc51108992ce403

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/mediainfo
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+libmediainfo
	TITLE:=Mediainfo
	URL:=http://mediaarea.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mediainfo/description
 MediaInfo is a convenient unified display of the most relevant
 technical and tag data for video and audio files.
endef

CONFIGURE_PATH:=Project/GNU/CLI
MAKE_PATH:=$(CONFIGURE_PATH)

define Package/mediainfo/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_BUILD_DIR)/$(CONFIGURE_PATH)/mediainfo $(1)/opt/bin
endef

$(eval $(call BuildPackage,mediainfo))
