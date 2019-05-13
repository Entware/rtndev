#
# Copyright (C) 2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# This is the last version which can be compiled against shared libfuse.
# Provided libfuse should be reworked for cross-compilation

include $(TOPDIR)/rules.mk

PKG_NAME:=mergerfs
PKG_VERSION:=2.25.1
PKG_REV:=3c1f19e85aa9085eeeb852251b021049c83f4856
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/trapexit/mergerfs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/mergerfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libfuse +libstdcpp
	TITLE:=a featureful union filesystem
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mergerfs/description
 mergerfs is a union filesystem geared towards simplifying storage and
 management of files across numerous commodity storage devices. It is similar
 to mhddfs, unionfs, and aufs.
endef

MAKE_FLAGS += \
	INTERNAL_FUSE=0

define Package/mergerfs/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(PKG_NAME) $(1)/opt/sbin
	$(LN) /opt/sbin/mergerfs $(1)/opt/sbin/mount.mergefs
endef

$(eval $(call BuildPackage,mergerfs))
