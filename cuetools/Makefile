# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware
#
# Abandoned in 2020

include $(TOPDIR)/rules.mk

PKG_NAME:=cuetools
PKG_VERSION:=1.4.1
PKG_REV:=365e379483ea180bcfa272d89a2524da55b1d600
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/svend/cuetools.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=b5471ee73f6e2d7777f4e482bb2810850bb8945bcfab35280bf2e8381d95ddf3

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/cuetools
	SECTION:=sound
	CATEGORY:=Sound
	TITLE:=cue and toc file parsers and utilities
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cuetools/description
 cuetools is a set of utilities for working with Cue Sheet (cue) and
 Table of Contents (toc) files.
endef

define Package/cuetools/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin
endef

$(eval $(call BuildPackage,cuetools))
