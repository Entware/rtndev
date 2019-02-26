#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=md5deep
PKG_VERSION:=4.4
PKG_REV:=b88a659572925e748115bdc3f4f64cacf15f2061
PKG_RELEASE:=1
PKG_FIXUP:=autoreconf

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/jessek/hashdeep
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/md5deep
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=tools to compute computer hashes, or message digests
	DEPENDS:=+libpthread +libstdcpp
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/md5deep/description
 md5deep is a set of programs to compute MD5, SHA-1, SHA-256, Tiger, or Whirlpool message digests
 on an arbitrary number of files. md5deep is similar to the md5sum program found in the GNU Coreutils package,
 but has additional features.
endef

define Package/md5deep/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/{hash,md5,sha1,sha256,tiger,whirlpool}deep $(1)/opt/bin
endef

$(eval $(call BuildPackage,md5deep))
