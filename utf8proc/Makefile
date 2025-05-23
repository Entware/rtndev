# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# only build static library (neovim)

include $(TOPDIR)/rules.mk

PKG_NAME:=utf8proc
PKG_VERSION:=2.10.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/JuliaStrings/utf8proc/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=6f4f1b639daa6dca9f80bc5db1233e9cbaa31a67790887106160b33ef743f136

PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=LICENSE.md
PKG_MAINTAINER:=Entware team, https://entware.net

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libutf8proc
  SECTION:=libs
  CATEGORY:=Libraries
  TITLE:=UTF8 processing
  URL:=https://juliastrings.github.io/utf8proc/
  BUILDONLY:=1
endef

define Package/libutf8proc/description
  utf8proc is a small, clean C library that provides Unicode
 normalization, case-folding, and other operations for data in the UTF-8
 encoding, supporting Unicode version 16.0.
endef

Build/Configure:=:

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/utf8proc.h $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libutf8proc.a $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/pkgconfig/*.pc $(1)/opt/lib/pkgconfig
endef

$(eval $(call BuildPackage,libutf8proc))
