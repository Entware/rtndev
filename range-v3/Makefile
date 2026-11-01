# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2023-2026 Entware

# XXX headers only (cryfs)

include $(TOPDIR)/rules.mk

PKG_NAME:=range-v3
PKG_VERSION:=0.12.0
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/ericniebler/range-v3/tar.gz/refs/tags/$(PKG_VERSION)?
PKG_HASH:=015adb2300a98edfceaf0725beec3337f542af4915cec4d0b89fa0886f4ba9cb

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=BSL-1.0
PKG_LICENSE_FILES:=LICENSE.txt

CMAKE_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/range-v3
  SECTION:=devel
  CATEGORY:=Development
  TITLE:=a library for C++14/17/20
  URL:=https://github.com/ericniebler/range-v3
  BUILDONLY:=1
endef

define Package/range-v3/description
  Range library for C++14/17/20, basis for C++20's std::ranges.
endef

$(eval $(call BuildPackage,range-v3))
