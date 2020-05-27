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
PKG_RELEASE:=2

PYPI_NAME:=psutil
PKG_HASH:=685ec16ca14d079455892f25bd124df26ff9137664af445563c1bd36629b5e0e

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-psutil
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	TITLE:=python3-psutil
	URL:=https://github.com/giampaolo/psutil
	MAINTAINER:=Entware team, https://entware.net
	DEPENDS:=+python3
endef

define Package/python3-psutil/description
 psutil is a cross-platform library for retrieving information onrunning
 processes and system utilization (CPU, memory, disks, network) in Python.
endef

define Package/psutil3
	$(call Package/python3-psutil)
	TITLE:=psutil scripts
	DEPENDS:=+python3-psutil
endef

define Package/psutil3/description
$(call Package/python3-psutil/description)
endef

define Package/psutil3/install
	$(INSTALL_DIR) $(1)$(PYTHON3_PKG_DIR)
	$(CP) \
	    $(PKG_BUILD_DIR)/scripts \
	    $(1)$(PYTHON3_PKG_DIR)/
	$(call Python3/FixShebang, \
		$(1)$(PYTHON3_PKG_DIR)/scripts/*.py \
		$(1)$(PYTHON3_PKG_DIR)/scripts/internal/*.py)
endef

$(eval $(call Py3Package,python3-psutil))
$(eval $(call BuildPackage,python3-psutil))
$(eval $(call BuildPackage,psutil3))
