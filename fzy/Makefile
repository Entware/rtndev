#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=fzy
PKG_VERSION:=1.0
PKG_REV:=f5d41e726cd997ba038815e218c48017228a8f0e
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/jhawthorn/fzy.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=1f3a48b11226e2e70cd3b6fa35024a47091a06e108e801f8feacee30173f4090

include $(INCLUDE_DIR)/package.mk

define Package/fzy
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	TITLE:=fuzzy finder for the terminal
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/fzy/description
 fzy is a fast, simple fuzzy text selector for the terminal
 with an advanced scoring algorithm.
endef

define Package/fzy/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/fzy $(1)/opt/bin
endef

$(eval $(call BuildPackage,fzy))
