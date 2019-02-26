#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=unionfs-fuse
PKG_VERSION:=2.0
PKG_REV:=c393877a8ebb1db9f61535043bd966faf2b87650
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/rpodgorny/unionfs-fuse.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/unionfs-fuse
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+fuse-utils +USE_UCLIBC:librt
	TITLE:=unionfs filesystem
	URL:=https://github.com/rpodgorny/unionfs-fuse.git
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/unionfs-fuse/description
  unionfs filesystem implementation which is way more flexible than the current in-kernel unionfs solution.
endef

CMAKE_OPTIONS += -Wno-dev -DOPTIONAL_INCLUDE_DIR=$(STAGING_DIR)/opt/include/fuse

define Package/unionfs-fuse/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,unionfs-fuse))
