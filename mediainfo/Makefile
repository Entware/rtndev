# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=mediainfo
PKG_VERSION:=24.01
PKG_REV:=d2c13410529435cc52757cd2dabe9d34c7e468f3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/MediaArea/MediaInfo.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=377ad6009efd7d818679235a2942cc51267d4bc9e1f1cd2a32d5a15fafff0e08

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
