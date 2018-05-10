#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=archivemount
PKG_VERSION:=0.8.12
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.cybernoia.de/software/archivemount
PKG_HASH:=247e475539b84e6d2a13083fd6df149995560ff1ea92fe9fdbfc87569943cb89

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/archivemount
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libfuse +libarchive
	TITLE:=FUSE file system for reading archives, supported by libarchive
	URL:=$(PKG_SOURCE_URL)
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
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/archivemount $(1)/opt/bin/
endef

$(eval $(call BuildPackage,archivemount))
