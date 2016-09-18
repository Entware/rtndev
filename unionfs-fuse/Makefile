#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=unionfs-fuse
PKG_VERSION:=1.0-20160829
PKG_REV:=352897fc1c16f1e27f06d25530d0db9df107bbe1
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
	DEPENDS:=+fuse-utils
	TITLE:=unionfs filesystem
	URL:=https://github.com/rpodgorny/unionfs-fuse.git
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/unionfs-fuse/description
  unionfs filesystem implementation which is way more flexible than the current in-kernel unionfs solution.
endef

CMAKE_OPTIONS += -DOPTIONAL_INCLUDE_DIR=$(STAGING_DIR)/opt/include/fuse

define Package/unionfs-fuse/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,unionfs-fuse))
