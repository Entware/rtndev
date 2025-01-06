# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2017-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=jdupes
PKG_VERSION:=1.28.0
PKG_REV:=6a4959ac7a084ae3f4ea717c3888e3adc1fffe9e
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://codeberg.org/jbruchon/jdupes.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=bd130419d5a19e5c85368b23bc02bf582285caebffe5438d9b9d60ca70e24522

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
