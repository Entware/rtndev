#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Used by weave-minimal only

include $(TOPDIR)/rules.mk

PKG_NAME:=python-werkzeug
PKG_VERSION:=0.16.0
PKG_RELEASE:=1

PYPI_NAME:=Werkzeug
PKG_HASH:=7280924747b5733b246fe23972186c6b348f9ae29724135a6dfc1e53cea433e7

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
#include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-werkzeug
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
#	DEPENDS:=+python
	TITLE:=python utilities for WSGI applications
	URL:=https://palletsprojects.com/p/werkzeug
	MAINTAINER:=Entware team, https://entware.net
	VARIANT:=python
endef

define Package/python-werkzeug/description
 Werkzeug started as simple collection of various utilities for WSGI
 applications and has become one of the most advanced WSGI utility modules.
endef

#$(eval $(call PyPackage,python-werkzeug))
#$(eval $(call BuildPackage,python-werkzeug))
