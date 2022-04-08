#
# Copyright (C) 2020-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# This is the last version which can be compiled against shared libfuse.
# Provided libfuse should be reworked for cross-compilation

include $(TOPDIR)/rules.mk

PKG_NAME:=mergerfs
PKG_VERSION:=2.33.4
PKG_REV:=77e6f400b5ce6b06b20e5d937b6cfbf2f3053eb5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/trapexit/mergerfs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=8d3ef427c3ec4340e0224355f92230c04d0a109e9189193ca3799372e94a5672

include $(INCLUDE_DIR)/package.mk

define Package/mergerfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libstdcpp
	TITLE:=a featureful union filesystem
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mergerfs/description
 mergerfs is a union filesystem geared towards simplifying storage and
 management of files across numerous commodity storage devices. It is similar
 to mhddfs, unionfs, and aufs.
endef

define Package/mergerfs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) \
		$(PKG_BUILD_DIR)/build/mergerfs \
		$(PKG_BUILD_DIR)/libfuse/build/mergerfs-fusermount \
		$(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libfuse/build/mount.mergerfs $(1)/opt/sbin
endef

$(eval $(call BuildPackage,mergerfs))
