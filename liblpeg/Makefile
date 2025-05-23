# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# only build static library (neovim)

include $(TOPDIR)/rules.mk

PKG_NAME:=lpeg
PKG_VERSION:=1.1.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.inf.puc-rio.br/~roberto/lpeg
PKG_HASH:=4b155d67d2246c1ffa7ad7bc466c1ea899bbc40fef0257cc9c03cecbaed4352a

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=lpeg.html

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/liblpeg
  SECTION:=lang
  CATEGORY:=Languages
  SUBMENU:=Lua
  TITLE:=LPeg - Parsing Expression Grammars For Lua
  URL:=https://www.inf.puc-rio.br/~roberto/lpeg
  DEPENDS:=+lua
  BUILDONLY:=1
endef

define Package/liblpeg/description
 LPeg is a new pattern-matching library for Lua, based on Parsing
 Expression Grammars (PEGs).
endef

$(eval $(call BuildPackage,liblpeg))
