#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-cups
PKG_VERSION:=2.0.1
PKG_RELEASE:=1

PYPI_NAME:=pycups
PKG_HASH:=57434ce5f62548eb12949ca8217f066f4eeb21a5d6ab8b13471dce350e380c90

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

# XXX error: option --single-version-externally-managed not recognized
PYTHON3_PKG_SETUP_ARGS:=

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
