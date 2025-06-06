# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2020-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=python3-uvloop
PKG_VERSION:=0.21.0
PKG_RELEASE:=1

PYPI_NAME:=uvloop
PKG_HASH:=3bf12b0fda68447806a7ad847bfa591613177275d35b6724b1ee573faa3704e3

PKG_LICENSE:=Apache-2.0 MIT
PKG_LICENSE_FILES:=LICENSE-APACHE LICENSE-MIT

PKG_BUILD_DEPENDS:=python-cython/host python-wheel/host

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-uvloop
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+libuv +python3-asyncio +python3-logging +python3-openssl +python3-unittest
	TITLE:=drop-in replacement of the built-in asyncio event loop
	URL:=http://github.com/MagicStack/uvloop
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python3-uvloop/description
 uvloop is a fast, drop-in replacement of the built-in asyncio event loop.
 uvloop is implemented in Cython and uses libuv under the hood.
endef

PYTHON3_PKG_BUILD_CONFIG_SETTINGS += \
	--build-option=build_ext \
	--build-option=--inplace \
	--build-option=--cython-always \
	--build-option=--use-system-libuv

$(eval $(call Py3Package,python3-uvloop))
$(eval $(call BuildPackage,python3-uvloop))
