# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=unionfs-fuse
PKG_VERSION:=3.5
PKG_REV:=021c2c6dd2d74ab2ecdfccc39caf39e19ea17b06
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/rpodgorny/unionfs-fuse.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=6643e122bfe98139c7456898973817437835b8e864b9f352a33457d11f3a48bb

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/unionfs-fuse
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+fuse3-utils
	TITLE:=unionfs filesystem
	URL:=https://github.com/rpodgorny/unionfs-fuse.git
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/unionfs-fuse/description
 unionfs filesystem implementation which is way more flexible than the current
 in-kernel unionfs solution.
endef

define Package/unionfs-fuse/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,unionfs-fuse))
