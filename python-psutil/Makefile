#
# Copyright (C) 2008-2015 OpenWrt
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-psutil
PKG_VERSION:=5.6.7
PKG_RELEASE:=1

PYPI_NAME:=psutil
PKG_HASH:=ffad8eb2ac614518bbe3c0b8eb9dffdb3a8d2e3a7d5da51c5b974fb723a5c5aa

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python-psutil/Default
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	TITLE:=python-psutil
	URL:=https://github.com/giampaolo/psutil
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python-psutil
	$(call Package/python-psutil/Default)
	DEPENDS:=+PACKAGE_python-psutil:python
	VARIANT:=python
endef

define Package/python3-psutil
	$(call Package/python-psutil/Default)
	DEPENDS:=+PACKAGE_python3-psutil:python3
	VARIANT:=python3
endef

define Package/python-psutil/description
 psutil is a cross-platform library for retrieving information onrunning
 processes and system utilization (CPU, memory, disks, network) in Python.
endef

define Package/python3-psutil/description
$(call Package/python-psutil/description)
.
(Variant for Python3)
endef

$(eval $(call PyPackage,python-psutil))
$(eval $(call BuildPackage,python-psutil))

$(eval $(call Py3Package,python3-psutil))
$(eval $(call BuildPackage,python3-psutil))
