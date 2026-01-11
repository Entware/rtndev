# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2017-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=jdupes
PKG_VERSION:=1.31.1
PKG_REV:=3a50704d4b53f30df099b7700d58789f9379c6e3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://codeberg.org/jbruchon/jdupes.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=776723f769736319d52a338881b53a6dd3c200c8b615251eb7576a53c409d060

PKG_BUILD_DEPENDS:=libjodycode

include $(INCLUDE_DIR)/package.mk

define Package/jdupes
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=duplicate files finder
	URL:=https://github.com/jbruchon/jdupes
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/jdupes/description
 Jdupes is a program for identifying or deleting duplicate files residing
 within specified directories.
endef

MAKE_VARS += \
	ENABLE_BTRFS=1 \
	STATIC_BTRFS_H=1

define Package/jdupes/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/jdupes $(1)/opt/bin
endef

$(eval $(call BuildPackage,jdupes))
