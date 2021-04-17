#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=tsmuxer
PKG_VERSION:=2.6.16-20210212
PKG_REV:=a50c2c5a169546beaa6fff93f1be785b3b8aed68
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/justdan96/tsMuxer.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=e3f93a4209e04251de4f6025b8e59e617f69a58ea693c928858b34edcec6ca13

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/devel/ninja/ninja-cmake.mk

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
