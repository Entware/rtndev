#
# Copyright (C) 2011-2025 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2020

include $(TOPDIR)/rules.mk

PKG_NAME:=archivemount
PKG_VERSION:=0.9.1
PKG_REV:=78c306538065de9b14f48cfc2024f50f843d3b29
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/cybernoid/archivemount.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=28c046130b8ea33c86b5add7db9e708f79f6985135d3c452e10da9d917ddc6f5

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/archivemount
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libfuse +libarchive
	TITLE:=FUSE file system for reading archives, supported by libarchive
	URL:=https://cybernoia.de/software/archivemount.html
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/archivemount/description
 Archivemount is a piece of glue code between libarchive
 (http://people.freebsd.org/~kientzle/libarchive/) and FUSE
 (http://fuse.sourceforge.net). It can be used to mount a (possibly compressed)
 archive (as in .tar.gz or .tar.bz2) and use it like an ordinary filesystem.
endef

define Package/archivemount/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/archivemount $(1)/opt/bin
endef

$(eval $(call BuildPackage,archivemount))
