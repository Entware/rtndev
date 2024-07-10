# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2024 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-cups
PKG_VERSION:=2.0.4
PKG_RELEASE:=1

PYPI_NAME:=pycups
PKG_HASH:=843e385c1dbf694996ca84ef02a7f30c28376035588f5fbeacd6bae005cf7c8d

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-cups
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	TITLE:=Python bindings for the CUPS API
	URL:=http://cyberelk.net/tim/software/pycups/
	MAINTAINER:=Entware team, https://entware.net
	DEPENDS:=+python3 +cups
endef

define Package/python3-cups/description
 This is a Python bindings for the CUPS API, known as pycups. It was written
 for use with system-config-printer, but can be put to other uses as well.
endef

$(eval $(call Py3Package,python3-cups))
$(eval $(call BuildPackage,python3-cups))
