#
# Copyright (C) 2008-2015 OpenWrt
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-psutil
PKG_VERSION:=5.7.0
PKG_RELEASE:=1

PYPI_NAME:=psutil
PKG_HASH:=685ec16ca14d079455892f25bd124df26ff9137664af445563c1bd36629b5e0e

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

define Package/psutil/Default
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	TITLE:=psutil scripts
	URL:=https://github.com/giampaolo/psutil
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/psutil
	$(call Package/psutil/Default)
	DEPENDS:=+python-psutil
endef

define Package/psutil/description
 psutil scripts.
endef

define Package/psutil3
	$(call Package/psutil/Default)
	DEPENDS:=+python3-psutil
endef

define Package/psutil3/description
$(call Package/psutil/description)
.
(Variant for Python3)
endef

define Package/psutil/install
	$(INSTALL_DIR) $(1)$(PYTHON_PKG_DIR)
	$(CP) \
	    $(PKG_BUILD_DIR)/scripts \
	    $(1)$(PYTHON_PKG_DIR)/
	$(call PyShebang,$(1)$(PYTHON_PKG_DIR)/scripts/*.py \
		$(1)$(PYTHON_PKG_DIR)/scripts/internal/*.py)
endef

define Package/psutil3/install
	$(INSTALL_DIR) $(1)$(PYTHON3_PKG_DIR)
	$(CP) \
	    $(PKG_BUILD_DIR)/scripts \
	    $(1)$(PYTHON3_PKG_DIR)/
	$(call Py3Shebang,$(1)$(PYTHON3_PKG_DIR)/scripts/*.py \
		$(1)$(PYTHON3_PKG_DIR)/scripts/internal/*.py)
endef

$(eval $(call PyPackage,python-psutil))
$(eval $(call BuildPackage,python-psutil))
$(eval $(call BuildPackage,psutil))

$(eval $(call Py3Package,python3-psutil))
$(eval $(call BuildPackage,python3-psutil))
$(eval $(call BuildPackage,psutil3))
