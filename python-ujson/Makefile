# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2024-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=ujson
PKG_VERSION:=5.11.0
PKG_RELEASE:=1

PYPI_NAME:=ujson
PKG_HASH:=e204ae6f909f099ba6b6b942131cee359ddda2b6e4ea39c12eb8b991fe2010e0

PKG_LICENSE:=BSD-3-Clause
PKG_LICENSE_FILES:=LICENSE.txt
PKG_MAINTAINER:=Entware team, https://entware.net

PKG_BUILD_DEPENDS:=python-setuptools-scm/host

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-ujson
  SECTION:=lang
  CATEGORY:=Languages
  SUBMENU:=Python
  TITLE:=Ultra fast JSON encoder and decoder
  URL:=https://github.com/ultrajson/ultrajson
  DEPENDS:=+libstdcpp +python3-light
endef

define Package/python3-ujson/description
  UltraJSON is an ultra fast JSON encoder and decoder written in pure
  C with bindings for Python 3.7+.
endef

define Package/python3-ujson/postrm
#!/bin/sh

rm -rf $(PYTHON3_PKG_DIR)/$(PYPI_NAME)-$(PKG_VERSION).dist-info
endef

$(eval $(call Py3Package,python3-ujson))
$(eval $(call BuildPackage,python3-ujson))
#$(eval $(call BuildPackage,python3-ujson-src))
