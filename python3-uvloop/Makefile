#
# Copyright (C) 2020-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python3-uvloop
PKG_VERSION:=0.17.0
PKG_RELEASE:=1

PYPI_NAME:=uvloop
PKG_HASH:=0ddf6baf9cf11a1a22c71487f39f15b2cf78eb5bde7e5b45fbb99e8a9d91b9e1

PKG_LICENSE:=MIT Apache-2.0

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-uvloop
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python3
	TITLE:=drop-in replacement of the built-in asyncio event loop
	URL:=http://github.com/MagicStack/uvloop
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python3-uvloop/description
 uvloop is a fast, drop-in replacement of the built-in asyncio event loop.
 uvloop is implemented in Cython and uses libuv under the hood.
endef

define Build/Configure
	( cd $(PKG_BUILD_DIR)/vendor/libuv; \
	$(CONFIGURE_VARS) \
	./configure \
		--target=$(GNU_TARGET_NAME) \
		--host=$(GNU_TARGET_NAME) \
		--build=$(GNU_HOST_NAME) \
		--prefix=/opt \
	);
	$(call Build/Configure/Default)
endef

$(eval $(call Py3Package,python3-uvloop))
$(eval $(call BuildPackage,python3-uvloop))
