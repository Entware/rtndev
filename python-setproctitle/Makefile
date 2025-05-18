# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=setproctitle
PKG_VERSION:=1.3.6
PKG_RELEASE:=1

PYPI_NAME:=setproctitle
PKG_HASH:=c9f32b96c700bb384f33f7cf07954bb609d35dd82752cef57fb2ee0968409169

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-setproctitle
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python3
	TITLE:=A Python module to customize the process title
	URL:=https://github.com/dvarrazzo/py-setproctitle
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python3-setproctitle/description
 A Python module to customize the process title.
endef

$(eval $(call Py3Package,python3-setproctitle))
$(eval $(call BuildPackage,python3-setproctitle))
