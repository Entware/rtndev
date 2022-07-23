#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=unionfs-fuse
PKG_VERSION:=3.2
PKG_REV:=453f588a0d227e31730244f45fce3adb0ecbe95d
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/rpodgorny/unionfs-fuse.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=fc52d594fd0bce232ef897a61de7a59b50401688fcc66e2e4e64fdfa4ca9d8bd

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/unionfs-fuse
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+fuse3-utils +USE_UCLIBC:librt
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
