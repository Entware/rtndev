# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tsmuxer
PKG_VERSION:=2.6.16-20240606
PKG_REV:=7f8667d1e6100a5b6407340d91ad80d57d976e58
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/justdan96/tsMuxer.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=4351d4db2f662e6b6c23b35b380953004f6463cffd31aa5323428b47d96ecba5

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/tsmuxer
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+libfreetype +libstdcpp
	TITLE:=transport stream (re)muxer
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/tsmuxer/description
 tsMuxer is a transport stream muxer for remuxing/muxing elementary streams,
 EVO/VOB/MPG, MKV/MKA, MP4/MOV, TS, M2TS to TS to M2TS. Supported video codecs
 H.264/AVC, H.265/HEVC, VC-1, MPEG2. Supported audio codecs AAC, (E-)AC3(DD+),
 DTS/ DTS-HD.
endef

define Package/tsmuxer/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tsmuxer $(1)/opt/bin
endef

$(eval $(call BuildPackage,tsmuxer))
